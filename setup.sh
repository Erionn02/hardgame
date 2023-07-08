echo "You might need to add sudo privileges for given user in order to install all dependencies"
echo "Add below line to /etc/sudoers if it is not present"
# Replace USERNAME with your username
# USERNAME ALL=(ALL) NOPASSWD:ALL

echo "Installing pip and conan..."
apt install -U python3-pip
pip install -U conan

echo "Resetting default conan profile..."
conan profile new default --detect --force
conan profile update settings.compiler.libcxx=libstdc++11 default
conan profile update conf.tools.system.package_manager:mode=install default
conan profile update conf.tools.system.package_manager:sudo=True default

echo "Installing system dependencies..."
echo "Installing libudev-dev..."
sudo apt install libudev-dev
echo "Installing pkg-config..."
sudo apt install pkg-config