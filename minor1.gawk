#   gawk -F, -f minor1.gawk grades.txt
#   gawk -F, '$3<3 && ($3-$2) < .1 {printf "%-20s %5.1f\n", $1, $3; }' gasoline.txt

BEGIN {
    total_sum = 0;
    total_count = 0;
    printf "%-20s %-6s\n", "Name", "Average";
}
NR > 1 && $3 == "A" {
    # Calculate the sum and count of test scores for each active student
    sum = 0;
    count = 0;
    for (i = 4; i <= NF; i++) {
        if ($i != "") {
            sum += $i;
            count++;
        }
    }
    if (count > 0) {
        avg = sum / count;
        total_sum += avg;
        total_count++;
        printf "%-20s %5.1f\n", $2 " " $1, avg;
    }
}
END {
    if (total_count > 0) {
        class_avg = total_sum / total_count;
        printf "\nTotal number of active students: %d\n", total_count;
        printf "Average class test score: %.1f\n", class_avg;
    }
}
