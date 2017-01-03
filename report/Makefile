TEX = latex --shell-escape -interaction=nonstopmode

all: report.pdf

.PHONY: clean purge
	
report.pdf: report.ps
	ps2pdf $<

report.ps: report.dvi
	dvips $<

report.dvi: report.tex
	$(TEX) $<
	$(TEX) $<

clean:
	@rm -f report.ps report.dvi report.aux report.log report.toc *~

mrproper: clean
	@rm -f report.pdf

purge: clean all
