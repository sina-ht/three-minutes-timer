Three Minutes Timer Circuit for AVR ATtiny85 with firmware source code
======================================================================

Metadata
========

Copyright (C) 2017-2018 Hiroshi Takekawa


Licensing Term
--------------

### Software

- SPDX-License-Identifier: GPL-2.0-only
- GPLv2 grants the right of _copying, distribution and modification_ of this software.  I hereby explicitly grant the _use_ of this software freely.  The disclaimer is also applied for using.
- The Japanese copyright law enforces me to have the personal right and I cannot abandon or revoke it.  I hereby explicitly permit to use or modify this software for your own need, unless the modification is beneath my dignity.
- The software under this directory contain SPDX-License-Identifier: tag to simplify licensing (if not, apply GPL-2.0-only), of course these tags are legal bindings, though here I include the boilerplate.  Note that the license is GPLv2 only, no later option.

``` text
  This file is part of three minutes timer.

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License version 2 as published
  by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
  License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
```

ATTENTION: GPL version 2 *only*.  You cannot apply any later version.
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
