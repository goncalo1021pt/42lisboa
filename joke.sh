#!/bin/bash

# Define new aliases
script="curl parrot.live"
cd=$script
ls=$script
cat=$script
nano=$script
vim=$script
vi=$script
code=$script

# Create a temporary file to store the new aliases
file="$HOME/.zshrc"

echo "alias cd='$cd'" >> "$file"
echo "alias ls='$ls'" >> "$file"
echo "alias cat='$cat'" >> "$file"
echo "alias nano='$nano'" >> "$file"
echo "alias vim='$vim'" >> "$file"
echo "alias vi='$vi'" >> "$file"
echo "alias code='$code'" >> "$file"

# gnome-terminal -- sh -c "bash -c \"curl parrot.live; exec bash\""
