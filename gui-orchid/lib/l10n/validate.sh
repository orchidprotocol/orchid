#!/bin/sh
#
# NOTE: flutter gen-l10n now does this for us.  Maintain this only if we require other validations.
#
# Read all of the arb files and check for missing keys as compared to 'en'.
#
en=app_en.arb
keys=/tmp/en.$$
check=/tmp/check.$$

function keys() {
    jq 'keys[]' | grep -v '@' | sort -u 
}

cat $en | keys > $keys

GLOBIGNORE="$en"
for f in *.arb
do
    cat $f | keys > $check
    d=$(diff $keys $check)
    if [ ! -z "$d" ]
    then 
        echo "\n$f keys differ:"
        echo "$d"
    fi
done

rm $keys $check
