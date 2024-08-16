// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    {"   ",
     "curl 'https://wttr.in/bangalore?format=3' -s | cut -d \" \" -f 1,4 | "
     "xargs echo",
     36000, 0},
    {"Vol: ",
     "pactl get-sink-volume @DEFAULT_SINK@ | grep -E -o '[0-9]*%' | xargs echo "
     "| awk '$1 == $2 {print $1} $1 != $2 {print \"check vol\"}'",
     0, 10},
    {"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g", 30, 0},
    {"Bat: ", "acpi -b | cut -d \",\" -f 2 | xargs echo", 5, 0},
    {"", "date '+%b %d (%a) %I:%M%p'", 5, 0},
};

// sets delimiter between status commands. NULL character ('\0') means no
// delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
