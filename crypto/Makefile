target := libhblk_crypto.a
objs := ec_create.c ec_from_pub.c ec_load.c ec_save.c ec_sign.c ec_to_pub.c ec_verify.c sha256.c
cc := gcc
flags := -Wall -Wextra -Werror -pedantic
all: $(target)
deps := $(patsubst %.c,%.o,$(objs))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.c=.o)
libhblk_crypto.a: $(objs)
	$(cc) $(flags) -o $@ $^ -lssl -lcrypto
%.o: %.c
	$(cc) $(flags) -c $< $(DEPFLAGS) -lssl -lcrypto
clean:
	rm -f $(targets) $(objs) $(deps)
