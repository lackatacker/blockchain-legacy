<<<<<<< HEAD
src = ec_create.c ec_from_pub.c ec_load.c ec_save.c ec_sign.c ec_to_pub.c ec_verify.c sha256.c
flags = -Wall -Wextra -Werror -pedantic
obj = $(patsubst %.c, %.o, $(src))
libhblk_crypto.a: $(obj)
	ar rcs libhblk_crypto.a $(objs)
=======
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
	$(cc) $(flags) -c $< $(DEPFLAGS)
>>>>>>> b4a918b97a5413aa2bdb8a76c8d6911ab8058905
clean:
	rm -f $(src) $(objs)
