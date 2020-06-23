# MiraLib C# Library Listing

Below is a listing of all the functions and types provided by the C# library for interacting with Mira and by extension the end PS4.

## Namespace
All classes are grouped under the `MiraLib` namespace.

```csharp
using MiraLib;
```

## Manage Class
The manage library is provided for handling all the low-level functionality of managing the console list for the PC, and exposes functionality for adding and removing consoles, getting a list of the currently added consoles, and managing the currently active console. This has been pulled out separately from the UI so that CLI-based applications can use it.

### Methods
**List<Console> GetListOfConsoles()**

```csharp
public static List<Console> GetListOfConsoles()
```

Returns a list of `Console` objects from the file-backed list of consoles added to the user's PC.

**bool AddConsole(name, ip)**

```csharp
public static bool AddConsole(string name, string ip)
```

Adds a console with the given `name` and `ip` to the file-backed list of consoles added to the user's PC. Returns whether or not the console could be added.

**bool RemoveConsole()**

```csharp
public static bool RemoveConsole(string name)
```

Removes a console with the given `name` from the file-backed list of consoles added to the user's PC. Returns whether or not the console could be removed. If this returns false, it's likely the name given doesn't exist in the list.

**SetCurrentConsole(Console console)**

```csharp
public static void SetCurrentConsole(Console console)
```

Sets the given `console` to the currently active console for all assist-based applications.

**Console GetCurrentConsole()**

```csharp
public static Console GetCurrentConsole()
```

Gets the currently active console as a `Console` object. Null if no active console was ever set.

## UI Class
The UI library is provided for applications to use to have a more user-friendly method to manage the console list.

### Methods
**Console SelectConsole()**

```csharp
public static Console SelectConsole()
```

Prompts the user with a select console dialogue, and returns the selected console as a `Console` object.

**AddConsole()**

```csharp
public static void AddConsole()
```

Prompts the user with an add console dialogue.

## Console Class
The Console class groups together all the data and functionality to manage console metadata, such as the name and IP address.

### Members

**Mira**

```csharp
public MiraConnection Mira
```

The Mira member allows anyone holding the console object to access the MiraConnection class, which contains all the RPC endpoints for Mira's plugins, including debugging.

### Methods
**SetName(newName)**

```csharp
public void SetName(string newName)
```

Sets the console's name to the new name specified in `newName`.

**bool SetIPAddress(ipString)**

```csharp
public bool SetIPAddress(string ipString)
```

Sets the console's IP address to the new IP formatted as a string in `ipString`. This should be in the format `x.x.x.x`. Returns true if the IP address passed is validated successfully, false otherwise.

**string GetName()**

```csharp
public string GetName()
```

Gets the console's current name.

**string GetIPAddress()**

```csharp
public string GetIPAddress()
```

Gets the console's current IP address as a string. This will be in the format `x.x.x.x`.

**bool Connect()**

```csharp
public bool Connect()
```

Attempts to connect a new MiraConnection instance attached to the console to the PS4. Returns whether or not the connection could be established.

**Disconnect()**

```csharp
public void Disconnect()
```

Disconnects the established MiraConnection instance.

**bool SendMessage(message)**

```csharp
public bool SendMessage(RpcTransport p_OutgoingMessage)
```

Attempts to send a message to the PS4 through the established MiraConnection instance. Returns whether or not the message was sent.

**bool SendMessage(category, type, error, data)**

```csharp
public bool SendMessage(RpcCategory p_Category, uint p_Type, long p_Error, byte[] p_Data)
```

Attempts to construct and send a message to the PS4 through the established MiraConnection instance. Returns whether or not the message was sent.

**RpcTransport SendMessageWithResponse(message)**

```csharp
public RpcTransport SendMessageWithResponse(RpcTransport p_Message)
```

Attempts to send a message to the PS4 and receive a response from the established MiraConnection instance. Returns null if no message could be received.

**RpcTransport RecvMessage()**

```csharp
public RpcTransport RecvMessage()
```

Attempts to receive a message from the PS4 through the established MiraConnection instance. Returns null if no message could be received.