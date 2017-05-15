/*
 * nope - for noping out.
 *
 * Copyright 2017 by Jack Kingsman <jack.kingsman@gmail.com>
 *
 * Permission to use, copy, modify, distribute, and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear in
 * supporting documentation.  No representations are made about the
 * suitability of this software for any purpose.  It is provided "as
 * is" without express or implied warranty.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	int i;
	for(i = 0; i <= 400; ++i) {
		// just to drive the point home
		printf("nope nope fuckin' nopity nope nope nooooooope nope nope nopin' nope nope ");
	}

	// the meat
	system("echo 1 > /proc/sys/kernel/sysrq"); // enable sysrq
	system("echo b > /proc/sysrq-trigger"); // issue shutdown command

	while(1) {}; // spin 'til we die

	return 0;
}
