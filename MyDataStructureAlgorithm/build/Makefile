#******************************************************************************
#*                                                                            *
#* This program is distributed in the hope that it will be useful, but        *
#* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY *
#* or FITNESS FOR A PARTICULAR PURPOSE. This file and program are licensed    *
#* under the GNU Lesser General Public License Version 3, 29 June 2007.       *
#* The complete license can be accessed from the following location:          *
#* http://opensource.org/licenses/lgpl-3.0.html                               *
#*                                                                            *
#* Author: Yun Li (yunli.open@gmail.com)                                      *
#*   Date: 05/22/2010                                                         *
#*                                                                            *
#******************************************************************************

#******************************************************************************
# REVISION HISTORY
# ================
# 
# Date     Version  Name          Description
# -------- -------  ------------  --------------------------------------------
#
# -------- -------  ------------  --------------------------------------------
#
#******************************************************************************
 
ROOT = $(realpath ..)
BUILD = $(realpath .)

COMMON_DIRS = \
    $(ROOT)/code/tools/err2str \
    $(ROOT)/code/platform/common/src \

    
NONUT_DIRS = \
    $(ROOT)/code/application/module \
    $(ROOT)/code/application/cpurate \
	$(ROOT)/code/application/list \
	$(ROOT)/code/application/dlist \
	$(ROOT)/code/application/clist \
	$(ROOT)/code/application/chtbl \
	$(ROOT)/code/application/bitree
    
UT_DIRS = \
    $(ROOT)/tests/platform/common \


MAKE_DIRS := $(COMMON_DIRS)

ifeq ("$(MAKECMDGOALS)", "")
MAKECMDGOALS = release
endif

ifeq ("$(MAKECMDGOALS)", "release")
MAKE_DIRS += $(NONUT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "debug")
MAKE_DIRS += $(NONUT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "unitest")
MAKE_DIRS += $(UT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "clean")
MAKE_DIRS += $(NONUT_DIRS) $(UT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "creport")
MAKE_DIRS += $(UT_DIRS)
endif
ifeq ("$(MAKECMDGOALS)", "scheck")
MAKE_DIRS += $(NONUT_DIRS)
endif

RM = rm
MKDIR = mkdir
MV = mv
RMFLAGS = -fr
MKDIRFLAGS = -p
RMS = release debug unitest $(DIR_COVERAGE) scheck $(DIR_PROFILE)

DIR_UNITEST = unitest
DIR_COVERAGE = coverage
DIR_PROFILE = profile

.PHONY: release debug clean touch unitest test force creport scheck dcheck dreport profile

release debug clean unitest scheck:
	@set -e; \
	for DIR in $(MAKE_DIRS); \
	do \
		cd $$DIR && $(MAKE) -r ROOT=$(ROOT) BUILD=$(BUILD) $@; \
	done
	@set -e; \
	if [ "$(MAKECMDGOALS)" = "clean" ] ; then $(RM) $(RMFLAGS) $(RMS) ; fi; \
	if [ "$(MAKECMDGOALS)" = "unitest" ] ; then touch $(DIR_UNITEST)/unitested; fi
	@echo ""
	@echo ":-) Completed"
	@echo ""

UTS = $(wildcard $(DIR_UNITEST)/unitest_*.exe)

ifeq ("$(MAKECMDGOALS)", "test")
ifeq ("$(wildcard $(DIR_UNITEST)/unitested)", "")
$(error Did you forget to run 'make unitest'?)
endif

$(DIR_UNITEST)/unitest_%: force 
	./$@
endif

test: $(UTS)
	@touch $(DIR_UNITEST)/tested

force:

touch:
	@echo "Processing ..."
	@find $(ROOT) -exec touch {} \;
	@echo ""
	@echo ":-) Completed"
	@echo ""

REPORT = unitest.report
TEMP = temp.report

ifeq ("$(MAKECMDGOALS)", "creport")
ifeq ("$(wildcard $(DIR_UNITEST)/tested)", "")
$(error Did you forget to run 'make unitest' and 'make test'?)
endif
endif

$(DIR_COVERAGE):
	$(MKDIR) $@

creport: $(DIR_COVERAGE)
	@set -e; \
	cd $(DIR_COVERAGE); \
	$(RM) $(RMFLAGS) *; \
	for DIR in $(MAKE_DIRS); \
	do \
		if ls $$DIR/uobjs/*.gcda > /dev/null 2>&1; then \
		    lcov -c -d $$DIR/uobjs -b $$DIR >> $(TEMP); \
		fi; \
	done ; \
	lcov -r $(TEMP) /usr/include/* tests/* tools/* c++/* unitest.h errstr.def -o $(REPORT); \
	genhtml $(REPORT); \
	$(RM) $(RMFLAGS) $(TEMP) $(REPORT)
	@echo ""
	@echo ":-) Generated"
	@echo ""
		
ifeq ("$(MAKECMDGOALS)", "dcheck")
ifeq ("$(wildcard $(DIR_UNITEST)/unitested)", "")
$(error Did you forget to run 'make unitest'?)
endif

$(DIR_UNITEST)/unitest_%: force 
	valgrind --leak-check=full --track-origins=yes --read-var-info=yes --malloc-fill=0xFF --log-file=$@.mem.log ./$@
	valgrind --tool=exp-ptrcheck --enable-sg-checks=yes --log-file=$@.ptr.log ./$@
endif

dcheck: $(UTS)
	@touch $(DIR_UNITEST)/dchecked
	@echo ""
	@echo ":-) Completed"
	@echo ""

ifeq ("$(MAKECMDGOALS)", "dreport")
ifeq ("$(wildcard $(DIR_UNITEST)/dchecked)", "")
$(error Did you forget to run 'make unitest' and 'make dcheck'?)
endif
endif

dreport:
	@cd $(DIR_UNITEST) && grep "ERROR SUMMARY" *.log | sed 's,\(.*\)\.log\(.*\)ERROR SUMMARY[ :]\(.*\),\1.log summary: \n   \3,g'
	@echo ""
	@echo ":-) Generated"
	@echo ""
		
ifeq ("$(MAKECMDGOALS)", "profile")
ifeq ("$(wildcard $(DIR_UNITEST)/unitested)", "")
$(error Did you forget to run 'make unitest'?)
endif

$(DIR_UNITEST)/unitest_%: force 
	valgrind -q --tool=callgrind --collect-jumps=yes --callgrind-out-file=$(basename $@).prof ./$@
endif

profile: $(UTS)
	@$(MKDIR) $(MKDIRFLAGS) $(DIR_PROFILE) && $(MV) $(DIR_UNITEST)/*.prof $(DIR_PROFILE)
	@echo ""
	@echo ":-) Completed"
	@echo ""
