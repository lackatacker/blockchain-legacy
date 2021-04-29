src = ec_create.c ec_from_pub.c ec_load.c ec_save.c ec_sign.c ec_to_pub.c ec_verify.c sha256.c
flags = -Wall -Wextra -Werror -pedantic
obj = $(patsubst %.c, %.o, $(src))
libhblk_crypto.a: $(obj)
	ar rcs libhblk_crypto.a $(obj)
clean:
	rm -f $(src) $(obj)
