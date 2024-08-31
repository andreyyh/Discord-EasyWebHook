# Discord-EasyWebHook
Send webhook messages to a Discord channel using an HTTP session in C++. 


## Example Usage

```cpp
#include "settings.h"

int main() {
    // Initialize HTTP session
    if (!initHTTP()) {
        std::cerr << "!HTTP session";
        return 1;
    }

    // Send a message with an embed
    SendEmbedHK("Discord CPP WebHook", "", "text without description"); 
    
    // Send a message without an embed
    SendMessageHK("Message without embed :joy:");
    
    // Finalize and close HTTP handles
    endHTTP(hRequest, hConnect, hSession);

    return 0;
}
```
## Output
<img src="image.png" alt="Output Example, c: -0.4 + 0.6i" width="500" />

## Discord
[Discord invite link](discord.gg/mXtg8NXv8q)
