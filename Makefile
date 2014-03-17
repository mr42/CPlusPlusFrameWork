SUBDIRS = Geometrics DataTypeExtensions Visualization
     
.PHONY: subdirs $(SUBDIRS)
     
subdirs: $(SUBDIRS)
     
$(SUBDIRS):
	$(MAKE) -C $@
