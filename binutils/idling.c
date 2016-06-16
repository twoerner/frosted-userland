/*
 *      This file is part of frosted.
 *
 *      frosted is free software: you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License version 2, as
 *      published by the Free Software Foundation.
 *
 *
 *      frosted is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with frosted.  If not, see <http://www.gnu.org/licenses/>.
 *
 *      Authors: Daniele Lacamera
 *
 */

#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void
main(int argc, char *argv[])
{
	int ledFd;
	uint8_t val = '0';

	ledFd = open("/dev/led0", O_RDWR, 0);

	if (ledFd >= 0) {
		while (1) {
			write(ledFd, &val, 1);
			val ^= 1;
			usleep(200000);
		}
	}
	else {
		/* GPIO unavailable, just sleep. */
		while(1) {
			sleep(1);
		}
	}
}
