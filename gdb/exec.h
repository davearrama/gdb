/* Work with executable files, for GDB, the GNU debugger.

   Copyright (C) 2003, 2007, 2008, 2009 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef EXEC_H
#define EXEC_H

#include "target.h"

struct target_section;
struct target_ops;
struct bfd;

extern struct target_ops exec_ops;

/* Builds a section table, given args BFD, SECTABLE_PTR, SECEND_PTR.
   Returns 0 if OK, 1 on error.  */

extern int build_section_table (struct bfd *, struct target_section **,
				struct target_section **);

/* Request to transfer up to LEN 8-bit bytes of the target sections
   defined by SECTIONS and SECTIONS_END.  The OFFSET specifies the
   starting address.

   Return the number of bytes actually transfered, or non-positive
   when no data is available for the requested range.

   This function is intended to be used from target_xfer_partial
   implementations.  See target_read and target_write for more
   information.

   One, and only one, of readbuf or writebuf must be non-NULL.  */

extern int section_table_xfer_memory_partial (gdb_byte *, const gdb_byte *,
					      ULONGEST, LONGEST,
					      struct target_section *,
					      struct target_section *);

/* Set the loaded address of a section.  */
extern void exec_set_section_address (const char *, int, CORE_ADDR);

#endif
