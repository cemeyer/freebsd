#include <sys/param.h>
#include <sys/conf.h>
#include <sys/filio.h>

#include <err.h>
#include <fcntl.h>

int
main(int argc, char **argv)
{
	int fd, one;

	if (argc < 2)
		errx(1, "usage: k_nextboot_helper /path/to/nextboot.conf");

	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		err(1, "open(%s)", argv[1]);

	one = 1;
	fd = ioctl(fd, FIONEXTBOOT, &one);
	if (fd < 0)
		err(1, "ioctl");

	return (0);
}
