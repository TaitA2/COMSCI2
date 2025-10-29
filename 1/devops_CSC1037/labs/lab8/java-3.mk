.PHONY CLEAN BUILD:
	javac *.java
.PHONY: clean
clean:
	rm -f $(addsuffix .class, $(basename $(wildcard *.java)))
