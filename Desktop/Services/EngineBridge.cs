using System;
using System.Runtime.InteropServices;
using System.Text;

namespace Basketball.Services;

public static class EngineBridge
{
    [DllImport(@"C:\Users\william\OneDrive\Documents\BasketballSimulator\BasketballEngine\cmake-build-debug\BasketballEngine.dll", CallingConvention = CallingConvention.Cdecl)]
    public static extern void hello();

    [DllImport(@"C:\Users\william\OneDrive\Documents\BasketballSimulator\BasketballEngine\cmake-build-debug\BasketballEngine.dll", EntryPoint = "getGameClockText", CallingConvention = CallingConvention.Cdecl)]
    private static extern void GetGameClockText(int gameId, StringBuilder buffer, int bufferSize);
    
    public static string GetGameClockTextImp(int gameId)
    {
        var buffer = new StringBuilder(32);
        GetGameClockText(gameId, buffer, buffer.Capacity);
        return buffer.ToString();
    }

    [DllImport(@"C:\Users\william\OneDrive\Documents\BasketballSimulator\BasketballEngine\cmake-build-debug\BasketballEngine.dll",
        EntryPoint = "GetGameSnapshot", CallingConvention = CallingConvention.Cdecl)]
    public static extern bool GetGameSnapshot(int gameId, out GameSnapshot snapshot);
}

[StructLayout(LayoutKind.Sequential)]
public struct Coordinate
{
    public int X;
    public int Y;
}

[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
public struct PlayerSnapshot
{
    public int Id;
    public int Position;
    public bool HasCoordinate;
    public Coordinate coordinate;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 64)]
    public string Name;
}

[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
public struct TeamSnapshot
{
    public int Id;
    public int Score;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 64)]
    public string Name;

    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 5)]
    public PlayerSnapshot[] Players;
}

[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
public struct GameSnapshot
{
    public int GameId;
    
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
    public string GameClock;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
    public string ShotClock;

    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
    public string Period;
    
    public bool ClockActive;
    
    public TeamSnapshot Home;
    public TeamSnapshot Away;
    
}