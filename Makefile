all: git push

git:
	git add .
	git commit

push:
	git push --tags
