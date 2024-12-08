# Reset
Color_Off='\033[0m'       # Text Reset

# Bold
BRed='\033[1;31m'         # Red
BGreen='\033[1;32m'       # Green
BBlue='\033[1;34m'        # Blue

cat_flag=false
grep_flag=false

verbose=false

while getopts 'cgv' flag; do
  case "${flag}" in
    c) cat_flag='true';;
    g) grep_flag='true';;
    v) verbose='true';;
    *) 
       exit 1 ;;
  esac
done

if [ $cat_flag == false ] && [ $grep_flag == false ]; then
    echo "No arguments provided: available '-c' (s21_cat), '-g' (s21_grep), '-v' logs results of comparisson" 
    exit 1
fi

outname=""

flags=()

if [ $cat_flag == true ]; then
    if [ $grep_flag == true ]; then
        grep_flag=false
        echo "two flags not supported, grep skipped"
    fi
    outname=res_cat_
    flags=(b e n s t v)
fi

if [ $grep_flag == true ]; then
    outname=res_grep_
    flags=(o e i v c n l s h)
fi

input_folder=sources
text_files=(lorem_ipsum.txt lorem_ipsum_copy.txt text_test.txt)
search=(Amet )

testsfolder=test_results
s21prefix=s21_
s21_filename=$s21prefix$outname
original_filename=$outname

mkdir -p $testsfolder

count_s=0
count_f=0
error_flag=false
files_count=${#text_files[@]}
flags_count=${#flags[@]}
search_count=${#search[@]}

for (( o = 1; o < (1 << files_count); o++ )); do

    test_files=()
    for (( f = 0; f < files_count; f++ )); do 
        if (((1 << f) & o)); then 
        test_files+=("$input_folder/${text_files[f]}")
        fi
    done

    for (( a = 0; a < search_count; a++ )); do
        search_list="${search[a]}"
    # for (( a = 1; a < (1 << search_count); a++ )); do  
    #     search_list=()                           
    #     for (( b = 0; b < search_count; b++ )); do     # loop over the bit slice position
    #         if (( (1 << b) & a )); then     # if the bit is set
    #             search_list+=("${search[b]}")
    #         fi
    #     done

        for (( i = 1; i < (1 << flags_count); i++ )); do  
            flags_list=()                           
            for (( j = 0; j < flags_count; j++ )); do
                if (( (1 << j) & i )); then
                    flags_list+=("${flags[j]}")
                fi
            done

            flags_prefix="$(IFS=''; printf '%s' "${flags_list[*]}")"
            test_filename="${test_files[*]}"

            search_prefix="${search_list[*]}"

            command=""
            if [ $cat_flag == true ]; then
                command="-$flags_prefix $test_filename"
            else
                command="-$flags_prefix $search_prefix $test_filename"
            fi
            
            current_flags_count=${#flags_list[@]}

            s21_name=$testsfolder/$current_flags_count-$flags_prefix-$s21_filename$ext
            orig_name=$testsfolder/$current_flags_count-$flags_prefix-$original_filename$ext 

            if [ $cat_flag == true ]; then
                ./../cat/s21_cat $command > $s21_name
                cat $command > $orig_name
            else
                ./../grep/s21_grep $command > $s21_name
                grep $command > $orig_name
            fi

            diff_result="$(diff -s $s21_name $orig_name)"
            expected_res="Files ${s21_name} and ${orig_name} are identical"

            if [ "$diff_result" == "$expected_res" ]; then
                rm $s21_name $orig_name
                (( count_s++ ))
                if [ $verbose == true ]; then
                    echo "${BGreen}$command${Color_Off}"
                fi
            else
                (( count_f++ ))
                error_flag=true
                echo "${BRed}$command fail ${Color_Off}"
                exit 1
            fi 
        done 
    done
done

if [ $error_flag == false ]; then
    rm -rf $testsfolder
fi

echo "${BBlue}
    / _ '_/'_ _               
   /)(-/(/// (-/) "

if [ $cat_flag == true ]; then
    echo "$    _                         
  _ _)-/ __  _ __/ __ _/_  __/
_) /__/     ( (//     /(-_) / ${Color_Off}"
else
    echo "    _                            
  _ _)-/ __   _ _ _   __ _/_  __/
_) /__/      (// (-/)    /(-_) / 
            _/    /   ${Color_Off}"
fi

echo "
${BGreen}Success: $count_s${Color_Off}\n   ${BRed}Fail: $count_f ${Color_Off}\n"