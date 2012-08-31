/*
 *int-test.c
 *
 *author: Saketh Kasibatla
 */
#include "int-test.h"

static FILE *fp = NULL;

int main(int argc, char *argv[])
{
    int i,k,*arr;
    size_t j;
    char *lib=LIBFILE,*func,*path=NULL, *error;
    int start=SIZE_START, end=SIZE_END, step=SIZE_STEP, tps = TRIALS_PER_SET;

    if(argc == 1){
        printf(USAGE);
        exit(0);
    }

    for(i=0;i<argc;i++){
        if( !strcmp(argv[i], "-l") ){
            lib=argv[++i];
        }else if( !strcmp(argv[i], "-f") ){
            func=argv[++i];
            if(path == NULL){
                path = (char *) calloc(strlen(func) +5, sizeof(char));
                strcpy(path,func);
                strcat(path,".dat");
            }
        }else if( !strcmp(argv[i], "-o") ){
            path = argv[++i];
        }else if( !strcmp(argv[i], "-s") ){
                start = atoi(argv[++i]);
        }else if( !strcmp(argv[i], "-e") ){
                end = atoi(argv[++i]);
        }else if( !strcmp(argv[i], "-t") ){
                step = atoi(argv[++i]);
        }else if( !strcmp(argv[i], "-r") ){
                tps = atoi(argv[++i]);
        }
    }
    
    void *libsorting;
    int *(*sort)(int *,size_t);
    

    libsorting = dlopen(lib, RTLD_LAZY);
    if(!libsorting){
        fprintf(stderr, "ERROR: %s\n", dlerror());
        exit(1);
    }
    
    dlerror();
    sort = (int *(*)(int *,size_t)) dlsym(libsorting, func);
    if(error=dlerror()){
        fprintf(stderr, "ERROR: %s\n", error);
        exit(1);
    }
    
    for(j=start;j<end;j+=step){
            printf("%d\n", j);
        for(i=0;i<NUM_SETS_PER_SIZE;i++){
            srand( time(NULL) );
            arr = get_array(j);
            for(k=0;k<tps;k++){
                write_to_file(j, run(arr,j,sort), path);
            }
            free(arr);
        }
    }

    dlclose(libsorting);
    fclose(fp);
    
    return(0);
}

    

int *get_array(size_t n)
{
    int *array = (int *) calloc(n , sizeof(int));
    size_t i;
    
    for(i=0;i<n;i++){
        array[i] = rand();
    }

    return array;
}

void write_to_file(size_t n, double t, char *f)
{
    if(fp == NULL){
        fp = fopen(f, "a+");
        if(!fp){
            fp = fopen(f, "w");
            fprintf(fp,"%s\n", FSTART);
        }
    }
    fprintf(fp,"%s%6d%s%6.2f%s\n", LSTART, n, LSEP, t, LSEP);


}

double run(int *a, size_t n, int *(*sort)(int *,size_t))
{
    double time;
    int *sorted;
    
    clock_t end, start = clock();

    sorted = sort(a,n);

    end = clock();
    time = (double) (end - start);

//    free(sorted);
    
    return time;
}
