/* Linux Projected Filesystem
   Copyright (C) 2019 GitHub, Inc.

   See the NOTICE file distributed with this library for additional
   information regarding copyright ownership.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library, in the file COPYING; if not,
   see <http://www.gnu.org/licenses/>.
*/

#include <dirent.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_common.h"

int main(int argc, char *const argv[])
{
	char *args[2];

	// TODO: add addition fileops (e.g., open|opendir|trunc|...)
	test_parse_opts(argc, argv, TEST_OPT_NONE, 2, 2, args,
			"opendir <path>");

	if (strcmp(args[0], "opendir") == 0) {
		DIR *dir;

		dir = opendir(args[1]);
		if (dir == NULL) {
			err(EXIT_FAILURE, "unable to open directory: %s",
			    args[1]);
		}
		if (closedir(dir) == -1) {
			err(EXIT_FAILURE, "unable to close directory: %s",
			    args[1]);
		}
	}
	else {
		test_exit_error(argv[0], "invalid file operation: %s",
				args[0]);
	}

	exit(EXIT_SUCCESS);
}

