PROBLEM=310
DIFF=diff
FILE=$(PROBLEM)
uva: $(PROBLEM).cpp
	g++ -o uva -Wall $(PROBLEM).cpp 

.PHONY: run
run: uva $(FILE).txt
	@echo running
	./uva <$(FILE).txt
.PHONY: runi
runi: uva 
	@echo running
	./uva
.PHONY: check
check: uva $(FILE).txt $(FILE).ans
	@echo checking-run
	./uva < $(FILE).txt >$(FILE).out
	@echo checking-diff
	$(DIFF) $(FILE).out $(FILE).ans
.PHONY: checkns
checkns: uva $(FILE).txt $(FILE).ans
	@echo checking-run
	./uva < $(FILE).txt >$(FILE).out
	@echo checking-diff
	$(DIFF) -b $(FILE).out $(FILE).ans
.PHONY:clean
clean: 
	rm uva *.o
.PHONY:echo
echo: 
	@echo $(PROBLEM)
.PHONY: test
test:
	echo $(a)
	
