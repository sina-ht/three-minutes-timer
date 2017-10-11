Three Minutes Timer Circuit for AVR ATtiny85 with firmware source code
======================================================================

Metadata
========

Copyright (C) 2017 Hiroshi Takekawa


Licensing Term
--------------

### Software

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; version 2 of the
License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.

ATTENTION: GPL version 2 only. You cannot apply any later version.
This situation may change in the future.

### Hardware

Absolutely NO WARRANTY.

Tested by the Author, but this schematic could be DANGEROUS.

Add, change or modify to fulfill your needs and safety.

No garber data.  You must create it or etch by yourself.


How to use
----------

+ Adjust Makefile to find your toolchain.
+ Just type 'make' to compile for your target board.
+ Run 'make install' to write to ATtiny85.  Adjust Makefile for changing the method to your writer.
+ Push SW to start timer, then after 3 minutes, alarm go off, after 1 more minute, alarm will stop.
+ Pushing SW during timer working, device states will be reset.


Contact
-------

E-mail: Hiroshi Takekawa <sian@big.or.jp>
