otp: BoB_OTP.c
	gcc -o $@ BoB_OTP.c -lcrypto
clear:
	rm otp