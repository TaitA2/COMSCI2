out = $(HOME)/local/bin
.PHONY: install
install:
	chmod +x $(wildcard [a-z]*)
	mkdir -p $(out)
	cp $(wildcard [a-z]*) $(out)
