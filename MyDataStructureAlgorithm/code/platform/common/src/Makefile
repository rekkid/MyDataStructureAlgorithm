EXE = 
LIB = libcommon.a

INCLUDE_DIRS = \
    $(ROOT)/code/platform/common/inc \


# all the error definition files should be put into ERROR_FILES variable
ERROR_FILES = \
    $(ROOT)/code/platform/common/inc/errmod.h \
	
LINK_LIBS = 

include $(BUILD)/c.rule

$(DIR_OBJS)/error.dep: genmark

# for cleaning the errstr.def and genmark files
RMS += errstr.def genmark

genmark: $(DIR_TARGET)/err2str.exe $(ERROR_FILES)
	$(DIR_TARGET)/err2str.exe $(ERROR_FILES) > errstr.def
	@touch genmark
