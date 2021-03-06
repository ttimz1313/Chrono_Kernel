# commit

c() { git commit -a; }

cn() { git commit -a --no-edit; }

ca() { git commit -a --amend; }

can() { git commit -a --amend --no-edit; }

cs() { git commit -as; }


# symbol "c" is already taken for commit, lets use "f" for cherry-pick based functions
# note. github links are allowed to be passed as argument

f() { 
   S=`echo $1 | cut -d / -f7`;
   git cherry-pick $S;
}

fn() { S=`echo $1 | cut -d / -f7`; git cherry-pick $S --no-commit; }

# cherry-pick few commits

fff() 
{ 
   for i in `seq 1 $#`
   do
      tmp=`echo $@ | cut -d " " -f $i`;
      S=`echo $tmp | cut -d / -f7`;
      git cherry-pick $S;
   done
}

# cherry-pick merge commit

fm(){ S=`echo $1 | cut -d / -f7`; git cherry-pick -m 1 $S; } 

# cherry-pick given range of commits

fr(){ S=`echo $1 | cut -d / -f7`; S1=`echo $2 | cut -d / -f7`; git cherry-pick $S"~1.."$S1; }

frn(){ S=`echo $1 | cut -d / -f7`; S1=`echo $2 | cut -d / -f7`; git cherry-pick $S".."$S1 --no-commit; } 


# reset

r() { git reset --hard HEAD ;}

# reset to given commit

rto() { git reset --hard $1; }

# reset(checkout) file/dir ($1) to given commit ($2)

rtof() { git reset -q $1 $2; git checkout $2; }


# revert

rv() { S=`echo $1 | cut -d / -f7`; git revert $S --no-commit; }

# revert merge commit

rvm() { S=`echo $1 | cut -d / -f7`; git revert $S -m1; }


# misc

n() { nano $@; } 

m() { git mergetool --tool=vim; } 

fix() { nano $1 $1.rej; }

cln() { git clean -fd; }

# view diff introduced by commit $1 for file/dir $2

view() { git diff $1~1 $1 $2; }
