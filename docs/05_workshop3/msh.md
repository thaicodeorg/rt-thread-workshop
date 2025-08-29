# RT-Thread Command 

# RT-Thread Finsh Commands Cheat Sheet

## 🐚 System Information
| Command      | Description                  | Example        |
|--------------|------------------------------|----------------|
| help         | Show all available commands  | `msh />help`   |
| ps           | Display list of threads      | `msh />ps`     |
| free         | Show memory usage information| `msh />free`   |
| version      | Display RT-Thread version    | `msh />version`|
| date         | Show current date and time   | `msh />date`   |
| list_device  | List all registered devices  | `msh />list_device` |
| list_timer   | Show software timers         | `msh />list_timer`  |
| list_mutex   | Display mutex objects        | `msh />list_mutex`  |
| list_sem     | Display semaphore objects    | `msh />list_sem`    |
| list_event   | Show event objects           | `msh />list_event`  |
| list_mq      | Display message queues       | `msh />list_mq`     |

## 📊 Thread Management
| Command  | Description                 | Example               |
|----------|-----------------------------|-----------------------|
| thread   | Thread management commands  | `msh />thread list`   |
| kill     | Terminate a thread          | `msh />kill <tid>`    |
| suspend  | Suspend a thread            | `msh />suspend <tid>` |
| resume   | Resume a suspended thread   | `msh />resume <tid>`  |

## 💾 File System Operations
| Command | Description              | Example                   |
|---------|--------------------------|---------------------------|
| ls      | List directory contents  | `msh />ls /`              |
| cd      | Change current directory | `msh />cd /flash`         |
| pwd     | Print working directory  | `msh />pwd`               |
| mkdir   | Create a new directory   | `msh />mkdir /data`       |
| rm      | Remove a file            | `msh />rm file.txt`       |
| cat     | Display file contents    | `msh />cat config.txt`    |
| echo    | Write text to file       | `msh />echo "text" > file.txt` |
| cp      | Copy files               | `msh />cp file1.txt file2.txt` |
| mv      | Move or rename files     | `msh />mv old.txt new.txt`|

## 📡 Network Commands
| Command   | Description                    | Example                         |
|-----------|--------------------------------|---------------------------------|
| ifconfig  | Configure network interfaces   | `msh />ifconfig`                |
| ping      | Ping network host              | `msh />ping 8.8.8.8`            |
| netstat   | Show network statistics        | `msh />netstat`                 |
| dns       | DNS configuration              | `msh />dns`                     |
| ntpdate   | Sync time with NTP server      | `msh />ntpdate pool.ntp.org`    |

## ⚙️ Hardware & Peripherals
| Command | Description           | Example              |
|---------|-----------------------|----------------------|
| pin     | GPIO pin control      | `msh />pin read 25`  |
| i2c     | I2C bus tools         | `msh />i2c probe`    |
| spi     | SPI bus tools         | `msh />spi probe`    |
| adc     | Read ADC values       | `msh />adc read 1`   |
| pwm     | PWM output control    | `msh />pwm set 1 5000 50` |
| uart    | UART configuration    | `msh />uart list`    |

## 🔧 Debugging & Testing
| Command   | Description                   | Example           |
|-----------|-------------------------------|-------------------|
| memtrace  | Memory allocation tracing     | `msh />memtrace`  |
| cpuusage  | CPU usage statistics          | `msh />cpuusage`  |
| log       | Log level control             | `msh />log level 1`|
| assert    | Trigger assertion test        | `msh />assert`    |
| reboot    | Reboot the system             | `msh />reboot`    |
| reset     | Reset the system              | `msh />reset`     |

## 🧩 Application Specific
| Command    | Description              | Example                           |
|------------|--------------------------|-----------------------------------|
| wifiscan   | WiFi network scanning    | `msh />wifiscan`                  |
| wifijoin   | Connect to WiFi network  | `msh />wifijoin SSID PASSWORD`    |
| http_get   | HTTP GET request         | `msh />http_get http://example.com` |
| mqtt_start | Start MQTT client        | `msh />mqtt_start`                |

## 🎯 Useful Command Combinations
| Purpose              | Command Sequence                                   |
|----------------------|----------------------------------------------------|
| System Status Check  | `ps → free → list_device → version`                |
| Network Diagnostics  | `ifconfig → ping google.com → netstat`             |
| File Management      | `ls / → cd /flash → cat config.txt`                |
| Hardware Debug       | `pin read 25 → adc read 1 → i2c probe`             |

## ⚡ Quick Reference
| Category     | Key Commands                        |
|--------------|-------------------------------------|
| System Info  | ps, free, version, list_device      |
| File System  | ls, cd, cat, rm, mkdir              |
| Network      | ifconfig, ping, netstat             |
| Hardware     | pin, i2c, spi, adc                  |
| Debugging    | memtrace, cpuusage, reboot          |

## 💡 Usage Tips
| Tip              | Description                           |
|------------------|---------------------------------------|
| Auto-complete    | Press TAB to auto-complete commands   |
| Command History  | Use ↑ and ↓ arrows to browse history  |
| Interrupt        | Ctrl + C to stop current command      |
| Logout           | Ctrl + D to logout from shell         |
| Help             | Use `help <command>` for specific help|

## 🆘 Troubleshooting Commands
| Issue              | Diagnostic Commands                             |
|--------------------|-------------------------------------------------|
| Thread stuck       | `ps → check thread status`                      |
| Memory leak        | `free → memtrace`                               |
| Network issues     | `ifconfig → ping → netstat`                     |
| Device not working | `list_device → check device status`             |
| File system errors | `ls → check mount points`                       |
