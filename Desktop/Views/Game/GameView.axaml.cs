using System;
using System.Threading.Tasks;
using Avalonia.Controls;
using Avalonia.Input;
using Avalonia.Threading;
using Basketball.Services;

namespace Basketball.Views.Game;

public partial class GameView : Window
{
    private readonly DispatcherTimer uiTimer;
    public GameView()
    {
        int index = 0;
        InitializeComponent();
        KeyDown += OnKeyDown;
        StartEngine();
        uiTimer = new DispatcherTimer
        {
            Interval = TimeSpan.FromMilliseconds(100)
        };
        uiTimer.Tick += (_, _) =>
        {
            if (!EngineBridge.GetGameSnapshot(0, out var game)) return;
            GameTime.Text = game.GameClock;
            HomeScore.Text = game.Home.Score.ToString();
            AwayScore.Text = game.Away.Score.ToString();
            ShotClock.Text = ":" + game.ShotClock;
            Period.Text =  game.Period;
            var home = game.Home;
            var away = game.Away;
            CourtGrid.UpdatePlayers(home, away);
            index++;
        };
        uiTimer.Start();
    }

    private void StartEngine()
    {
        Task.Run(() =>
        {
            EngineBridge.hello();
        });
    }
    private void OnKeyDown(object? sender, KeyEventArgs e)
    {
        if (e.Key == Key.F11) {
            
            WindowState = WindowState == WindowState.FullScreen
                ? WindowState.Maximized
                : WindowState.FullScreen;

            e.Handled = true;
        }
    }
}