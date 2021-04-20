#!/bin/bash
# author: Whizzzkid (me@nishantarora.in)
# modified by: allanaes (twitter.com/allanaes)

# Base URL.
bing="http://www.bing.com"

# API end point.
api="/HPImageArchive.aspx?"

# Response Format (json|xml).
format="&format=js"

# For day (0=current; 1=yesterday... so on).
day="&idx=0"

# Market for image.
market="&mkt=en-US"

# API Constant (fetch how many).
const="&n=1"

# Image extension.
extn=".jpg"

# Size.
size="1920x1080"

# Collection Path.
path="$HOME/GoogleDrive/hamidtessilimi@gmail.com/PICTURES/Wallpapers/Desktop"

# Make it run just once (useful to run as a cron)
#run_once=false
run_once=false

while getopts "1" opt; do
  case $opt in
    1 )
      run_once=true
      ;;
    \? )
      echo "Invalid option! usage: \"$0 -1\", to run once and exit"
      exit 1
      ;;
  esac
done

########################################################################
#### DO NOT EDIT BELOW THIS LINE #######################################
########################################################################

# Required Image Uri.
reqImg=$bing$api$format$day$market$const

while [ 1 ]
do

  # Logging.
  echo "Pinging Bing API..."

  # Fetching API response.
  apiResp=$(curl -s $reqImg)
  if [ $? -gt 0 ]; then
    echo "Ping failed!"
    exit 1
  fi

  # Default image URL in case the required is not available.
  #defImgURL=$bing$(echo $apiResp | grep -oP "url\":\"[^\"]*" | cut -d "\"" -f 3)
  defImgURL=$(curl -s https://www.bing.com/HPImageArchive.aspx\?format\=js\&idx\=0\&n\=1\&mkt\=en-US | sed 's/.*url":"//' | sed 's/","urlbase".*$//' | awk '{$1=$1};1' | sed 's/^/https:\/\/www.bing.com/')


  # Req image url (raw).
  #reqImgURL=$bing$(echo $apiResp | grep -oP "urlbase\":\"[^\"]*" | cut -d "\"" -f 3)"_"$size$extn
  reqImgURL=$(curl -s https://www.bing.com/HPImageArchive.aspx\?format\=js\&idx\=0\&n\=1\&mkt\=en-US | sed 's/.*url":"//' | sed 's/","urlbase".*$//' | awk '{$1=$1};1' | sed 's/^/https:\/\/www.bing.com/')


  # Checking if reqImgURL exists.
  if ! wget --quiet --spider $reqImgURL; then
    reqImgURL=$defImgURL
  fi

  # Logging.
  echo "Bing Image of the day: $reqImgURL"

  # Getting Image Name.
  # @allanaes Modified script to get clean file name
  imgNameOrig=${reqImgURL##*/}
  img1=${imgNameOrig/th\?id=OHR./}
  imgName=${img1%&rf*}

  # Create Path Dir.
  mkdir -p $path

  # Saving Image to collection.
  curl -s -o $path$imgName $reqImgURL

  # Logging.
  echo "Saving image to $path$imgName"

  # @allanaes Modified script to work with KDE Plasma 5
  if [ "$XDG_CURRENT_DESKTOP" = "KDE" ]
  then
    # @allanaes Modified script: We will dump the command to a file
    # So we need to prepare the template command
    read -r -d '' changeDesktopCmd << EOM
qdbus org.kde.plasmashell /PlasmaShell org.kde.PlasmaShell.evaluateScript 'string:
var Desktops = desktops();                                                                                                                       
for (i=0;i<Desktops.length;i++) {
        d = Desktops[i];
        d.wallpaperPlugin = "org.kde.image";
        d.currentConfigGroup = Array("Wallpaper",
                                    "org.kde.image",
                                    "General");
        d.writeConfig("Image", "file:///__BING_WALLPAPER__");
}'
EOM
    
    # @allanaes Modified script: Replace wallpaper placeholder to actual path and file
    changeWall=${changeDesktopCmd/__BING_WALLPAPER__/$path$imgName}
    
    # @allanaes Modified script: Dump the command for easier execution
    scriptName="_KDEBing"
    echo '#!/bin/bash' > $path$scriptName
    echo '' >> $path$scriptName
    echo $changeWall >> $path$scriptName
    
    # @allanaes Modified script: Execute delayed command to change current wallpaper
    sleep 10
    bash $path$scriptName
    
    # @allanaes Modified script: Just echo a message.
    # If the wallpapaer is not changed, the command above does NOT WORK anymore.
    echo "KDE Wallpaper set to $imgName"    
  elif [ "$XDG_CURRENT_DESKTOP" = "XFCE" ]
  then
    xres=($(echo $(xfconf-query --channel xfce4-desktop --list | grep last-image)))
    for x in "${xres[@]}"
    do
      xfconf-query --channel xfce4-desktop --property $x --set $path$imgName
    done    
  # Set the wallpaper for unity, gnome3, cinnamon.
  elif gsettings set org.gnome.desktop.background picture-uri "file://$path$imgName";
  then
    #Logging
    # Set the view to zoom,
    gsettings set org.gnome.desktop.background picture-options "zoom"    
  else
    "$XDG_CURRENT_DESKTOP not supported."
    break
  fi

  echo "New wallpaper set successfully for $XDG_CURRENT_DESKTOP."
  
  # If -1 option was passed just run once
  if [ $run_once == true ];then
    break
  fi

  # Re-checks for updates every 3 hours.
  #sleep 60
  sleep 10800
done
