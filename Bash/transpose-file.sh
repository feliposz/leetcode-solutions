# Read from the file file.txt and print its transposed content to stdout.
cat file.txt | awk '{for(x=1;x<=NF;x++)if(NR==1)LINES[x]=$x;else LINES[x]=LINES[x]" "$x}END{for(x=1;x<=length(LINES);
x++) print LINES[x]}'