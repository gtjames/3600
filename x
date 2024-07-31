    6  ls | gawk 'BEGIN { print "List of html files:" /\.html$/ { print }END { print "There you go!" }'\nls | gawk 'BEGIN { print "List of html files:"} /\.html$/ { print }END { print "There you go!" }'\nls | gawk 'BEGIN { print "List of html files:"} /\.csv$/ { print }END { print "There you go!" }'\nls | gawk 'BEGIN { print "List of html files:"} /\.json$/ { print }END { print "There you go!" }'\ngawk /Capt/ {$3 $2} Titanic.csv
    7  gawk /Capt/ {print $3 $2} Titanic.csv
   8  gawk /Capt/ {print} Titanic.csv
    9  gawk /Capt/ {print $3, $2} Titanic.csv
   10  gawk /Capt/ {print ($3, $2)} Titanic.csv
   11  gawk '/Capt/ {print ($3, $2)}' Titanic.csv
   12  gawk -F, '/Capt/ {print ($3, $2)}' Titanic.csv
   13  gawk -F, '/Capt/ {print ($31, $2)}' Titanic.csv
   21  gawk -F, '/3rd/ {print ($4, $3)}' Titanic.csv
   22  gawk -F, 'BEGIN{sum = 0} /3rd/ {sum += $3} END{print (#sum)}' Titanic.csv
   24  gawk -F, 'BEGIN{sum = 0} /3rd/ {sum += $3, print($3)} END{print ($sum)}' Titanic.csv
   25  gawk -F, 'BEGIN{sum = 0} /3rd/ {sum += $3; print($3)} END{print ($sum)}' Titanic.csv
   26  gawk -F, 'BEGIN{sum = 0} /3rd/ {sum = sum+ $3, print($3)} END{print ($sum)}' Titanic.csv
   27  gawk -F, 'BEGIN{sum = 0} /3rd/ {sum = sum+ $3 print($3)} END{print ($sum)}' Titanic.csv
