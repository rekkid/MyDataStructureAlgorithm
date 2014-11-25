/******************************************************************************
 *                                                                            *
 * This program is distributed in the hope that it will be useful, but        *
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
 * or FITNESS FOR A PARTICULAR PURPOSE. This file and program are licensed    *
 * under the GNU Lesser General Public License Version 3, 29 June 2007.       *
 * The complete license can be accessed from the following location:          *
 * http://opensource.org/licenses/lgpl-3.0.html                               *
 *                                                                            *
 * Author: Yun Li (yunli.open@gmail.com)                                      *
 *   Date: 03/08/2010                                                         *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
  REVISION HISTORY
  ================

  Date     Version  Name          Description
  -------- -------  ------------  --------------------------------------------

  -------- -------  ------------  --------------------------------------------

 ******************************************************************************/
#include "unitest.h"
#include "list.h"

void unitest_main (int argc, char *argv[])
{
	List list;

	/* Test list_init. */
	list_init(&list, NULL);

	UNITEST_EQUALS(list.destroy, 0);
	UNITEST_EQUALS(list.head, NULL);
	UNITEST_EQUALS(list.tail, NULL);

	/* Test list_ins_next */
	//list_ins_next(&list, );



}

