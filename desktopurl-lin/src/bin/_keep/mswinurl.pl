#!/usr/bin/perl
# Script to make Microsoft Windows Internet Shortcuts (*.url) work on Linux.

my $browser = 'sensible-browser';  # use the system default browser

while (<>) {
    # match any line of the form "URL = something-without-spaces"
    if (/^\s*URL\s*=\s*(\S+)\s*$/) {
        exec $browser, $1;         # successful exec never returns
        die "$0: could not launch $browser: $!\n";
    }
}
