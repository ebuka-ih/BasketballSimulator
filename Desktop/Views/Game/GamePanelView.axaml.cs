using System.Collections.ObjectModel;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Markup.Xaml;

namespace BasketballEngine.Desktop.Views.Game;

public partial class GamePanelView : UserControl
{
    public ObservableCollection<GameItem> Games;
    public GamePanelView()
    {
        InitializeComponent();
        ActiveGames.ItemsSource = new string[]{
            "Game1",  "Game2", "Game3", "Game4",  "Game5", 
            "Game6", "Game7", "Game8", "Game9",  "Game10"};
        
    }
    public class GameItem
    {
        public string HomeTeam { get; set; } = "Home";
        public string AwayTeam { get; set; } = "Away";
        public string HomeScore { get; set; } = "0";
        public string AwayScore { get; set; } = "0";
        public string Status { get; set; } = "In Progress";
    }
}