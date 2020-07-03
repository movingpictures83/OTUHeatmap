# OTUHeatmap
# Language: C++
# Input: TXT
# Output: prefix
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: Qiime 1.9.1, Python 2.7

Plot a heatmap of each the relative abundances of OTUs in a set of samples.

The plugin accepts a TXT file of keyword-value pairs, tab-delimited:

otutable (BIOM file of OTUs)
tree (TRE file of taxonomic tree)

It produces as output a PDF file of the heatmap of OTU abundances, into the provided output folder.  It also will automatically copy these into the parent folder of this directory.
