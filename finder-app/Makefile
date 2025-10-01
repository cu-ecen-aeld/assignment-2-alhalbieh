writer: writer.c
ifdef CROSS_COMPILE
	$(CROSS_COMPILE)gcc -o writer writer.c
else
	gcc -o writer writer.c
endif
clean:
	rm -f writer
