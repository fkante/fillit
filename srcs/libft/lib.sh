#! /bin/bash

# Create a header file with every .c inside $2$1

# usage:sh g	et_protos terminal ../srcs/minishell/
# $1 (terminal) will be the name of directory of interest
# $2 (../srcs/minishell/) will be the path (from where the .sh is executed)
# $2 is fully optional

path=includes/auto/
prefix=auto_
suffix=_H
extension=.h
name=$path$prefix$1$extension
spe=$prefix$1$suffix

rm -rf $name

echo "#ifndef \c" > $name
printf $spe | awk '{ print toupper($1) }' >> $name
echo "# define \c" >> $name
printf $spe | awk '{ print toupper($1) }' >> $name
echo "" >> $name

find $3$2$1 -type f -exec cat {} \+ |
grep -e int -e char -e void -e size_t -e t_list -e "t_tab " -e "\.\.\."|
grep -e ft_ -e nalloc -e get_next_line |
grep -v -e ":+:" -e static -e while -e if -e ";" -e "#include " -e "=" -e "->" |
tr -s '\t' '\t\t' |
sort >> $name
sed -i '' "s~)$~);~g" $name
sed -i '' "s~~~g" $name
sed -i '' "s~int~int~g" $name
sed -i '' "s~intmax_t~in							tmax_t~g" $name

echo "\n#endif" >> $name

echo "includes/auto_$1.h\t\tcreated"
	

