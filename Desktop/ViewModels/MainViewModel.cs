using Basketball.Views.Game;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;

namespace BasketballEngine.Desktop.ViewModels;

public partial class MainViewModel : ViewModelBase
{
    [ObservableProperty] private ViewModelBase? _currentViewModel;
    
    public GamePanelViewModel GamePanel { get; }

    public MainViewModel()
    {
        GamePanel = new GamePanelViewModel();
        CurrentViewModel = this;
    }
    [RelayCommand]
    private void ShowGamePanel()
    {
        
        CurrentViewModel = GamePanel;
        
    }
}