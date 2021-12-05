.PHONY: clean All

All:
	@echo "----------Building project:[ UOCContacts - Debug ]----------"
	@cd "UOCContacts" && "$(MAKE)" -f  "UOCContacts.mk"
	@echo "----------Building project:[ UOC20211 - Debug ]----------"
	@"$(MAKE)" -f  "UOC20211.mk"
clean:
	@echo "----------Cleaning project:[ UOCContacts - Debug ]----------"
	@cd "UOCContacts" && "$(MAKE)" -f  "UOCContacts.mk"  clean
	@echo "----------Cleaning project:[ UOC20211 - Debug ]----------"
	@"$(MAKE)" -f  "UOC20211.mk" clean
