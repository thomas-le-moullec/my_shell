#!/bin/bash

ulimit -c 0

export PATH="/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin:/usr/heimdal/sbin:~/bin:/home/payrau_a/.cask/bin"

export EDITOR='emacs'
export HISTSIZE=1000
export MAIL="/u/all/${USER}/mail/${USER}"
export PAGER='less'

#export PS1="\\[$(tput setaf 1)\\]\\u@\\h:\\w #\\[$(tput sgr0)\\]"
export PS1='\[\e[01;30m\]Oº°‘¨`if [ $? = 0 ]; then echo "\[\e[32m\] ✔ "; else echo "\[\e[31m\] ✘ "; fi`\[\e[01;37m\]`[[ $(git status 2> /dev/null | head -n2 | tail -n1) != "# Changes to be committed:" ]] && echo "\[\e[31m\]" || echo "\[\e[33m\]"``[[ $(git status 2> /dev/null | tail -n1) != "nothing to commit (working directory clean)" ]] || echo "\[\e[32m\]"`$(__git_ps1 "(%s)\[\e[00m\]")\[\e[01;34m\]\w\[\e[00m\]\[\e[1;36m\]\$\[\e[00m\] '

export SAVEHIST=1000
export WATCH='all'

alias ll='ls -l'
alias la='ls -a'
alias j='jobs'
alias emacs='emacs -nw'
alias ne='emacs -nw'
alias pu="push_that.sh"
alias cl="mr_clean"
alias re="prepare_my_repo.sh"
alias lk='xlock -bg blue -fg white -mode strange'
##alias lk='xlock -bg blue -fg white -mode euler2d'
##alias lk='xlock -bg blue -fg white -mode kumppa'
alias moulinette='~/bin/moulinette.py -score -nocheat -libc'
alias batman='cat ~/bin/batman.sh &&upower -i /org/freedesktop/UPower/devices/battery_BAT0| grep -E "state|to\ full|percentage"'
alias son='amixer sset Master'
alias light='xbacklight -set'
alias dualscreen='xrandr --output DP2 --auto'
alias dualscreen2='xrandr --output DP2 --right-of eDP1'
alias HDscreen='xrandr --output HDMI1 --mode 1920x1080'
alias HDscreen2='xrandr --output HDMI1 --mode 1920x1080 --right-of eDP1'
alias ram='htop'
alias use='cat ~/bin/use_root'
alias valou='valgrind --leak-check=full --show-reachable=yes'
alias russe='[ $[ $RANDOM % 6 ] == 0 ] && echo "You die" || echo "You live"'
# alias chromium='chromium --disable-namespace-sandbox'
alias clion='~/bin/clion'
alias webstorm='~/bin/webstorm'
alias tron='ssh sshtron.zachlatta.com'
alias mk='make re ; cl'

export LD_LIBRARY_PATH="/home/payrau_a/.froot/lib/"
export C_INCLUDE_PATH="/home/payrau_a/.froot/include/"
export CPLUS_INCLUDE_PATH="/home/payrau_a/.froot/include/"
