all: xipfstool
CFLAGS+=-I$(FROSTED_KERNEL)


xipfstool: xipfs.c
	if [ ! -d "$(FROSTED_KERNEL)" ]; then \
		echo "the environment variable 'FROSTED_KERNEL' needs to exist"; \
		echo "and point to the base directory of your FROSTED kernel sources"; \
		exit 1; \
	else \
		gcc $(CFLAGS) -o $@ $^; \
	fi;

clean:
	rm -f xipfstool
