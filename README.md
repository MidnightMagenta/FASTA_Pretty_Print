# FASTA To Pretty Print
Small command line utility for converting FASTA formated DNA, RNA, or protein sequences to pretty print.

## How to use
Run the application from the command line with the following arguments:

`-i [path]` - specifies the input file path

`-o [path]` - specifies the output file path

`-l [n]` - specifies the number of characters per line in the resultant pretty print

### Example

Input.txt:
```
>SomeDNASequence
acttttctgtggctacatatatatatgcaaaagacaaaagataacccagttaaatagtactattttgtgtcaatctcctc
atcgatctcattttgtctctgattagagcttcaaaatggataccggtgaaggtaagtcagcacaagcaccaaacatcaat
gctccacccactggacaatggactactggtttatttgattgctttgacgacactggaatttgctgttctacctggctctg
tccacattccatttttggtcccaatgcggaaattatagaccaaggaagaacatcttctagatctgcaacttacatatttt
gtggccttagcttggttgggtgggcattcttatattcattcaaattcagaagcaagctaagagccctctacaacttacca
gaagaaccatgcggagatctttgcgttcactactgttgtttagtgtttgctattagccaagagcgacgagaacttaaaaa
ccgtggattggacacctcagtaggttggaagggaaacgaattcgcaatgagaaaagctaacctagtacctccaccagttg
tgcccgccatgactcgctagaatttctcatgtcaacgatacaatttggagtagacttgctgttatatacaatctggtgct
ataagttaggagtttaactttcttagtttttaatatctagtatcagttgctttataatttcctgttgttgagtatgtagc
cactttgaattcaataaagaagcatcagtttgcaagttacatatata
```

Running the command:
`fastapp -i Input.txt -o Output.txt -l 50`
Will produce the following `Output.txt`:
```
    SomeDNASequence
       0	acttttctgt ggctacatat atatatgcaa aagacaaaag ataacccagt 
      50	taaatagtac tattttgtgt caatctcctc atcgatctca ttttgtctct 
     100	gattagagct tcaaaatgga taccggtgaa ggtaagtcag cacaagcacc 
     150	aaacatcaat gctccaccca ctggacaatg gactactggt ttatttgatt 
     200	gctttgacga cactggaatt tgctgttcta cctggctctg tccacattcc 
     250	atttttggtc ccaatgcgga aattatagac caaggaagaa catcttctag 
     300	atctgcaact tacatatttt gtggccttag cttggttggg tgggcattct 
     350	tatattcatt caaattcaga agcaagctaa gagccctcta caacttacca 
     400	gaagaaccat gcggagatct ttgcgttcac tactgttgtt tagtgtttgc 
     450	tattagccaa gagcgacgag aacttaaaaa ccgtggattg gacacctcag 
     500	taggttggaa gggaaacgaa ttcgcaatga gaaaagctaa cctagtacct 
     550	ccaccagttg tgcccgccat gactcgctag aatttctcat gtcaacgata 
     600	caatttggag tagacttgct gttatataca atctggtgct ataagttagg 
     650	agtttaactt tcttagtttt taatatctag tatcagttgc tttataattt 
     700	cctgttgttg agtatgtagc cactttgaat tcaataaaga agcatcagtt 
     750	tgcaagttac atatata    
```
