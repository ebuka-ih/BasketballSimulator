using Avalonia;
using Avalonia.Controls;
using Avalonia.Media;
using Basketball.Services;

namespace Basketball.Controls;

public class CourtGridControl : Control
{
    private int rows = 51;
    private int columns = 95;

    private TeamSnapshot? _home;
    private TeamSnapshot? _away;

    public void UpdatePlayers(TeamSnapshot home, TeamSnapshot away)
    {
        _home = home;
        _away = away;

        InvalidateVisual();
    }
    
    public override void Render(DrawingContext context)
    {
        base.Render(context);
        var cellWidth = Bounds.Width / columns;
        var cellHeight = Bounds.Height / rows;

        const double radius = 2;
        context.DrawRectangle(Brushes.Transparent, null, Bounds);
        for (var x = 0; x < columns; x++) {
            for (var y = 0; y < rows; y++) {
                var center = new Point((x + 0.5) * cellWidth,(y + 0.5) * cellHeight);
                switch (x, y) {
                    case (93,25): 
                    case(1, 25):
                    case(47, 25):
                        context.DrawEllipse(Brushes.Cyan, null, center, radius, radius);
                        break;
                    default:
                        //context.DrawEllipse(Brushes.Gray, null, center, radius, radius);
                        break;
                }
            }
        }
        if (_home is { } homeTeam)
            DrawPlayers(context, homeTeam,  new SolidColorBrush(Color.Parse("#a635fc")));

        if (_away is { } awayTeam)
            DrawPlayers(context, awayTeam, new SolidColorBrush(Color.Parse("#119909")));
    }

    private void DrawPlayers(DrawingContext context, TeamSnapshot team, IBrush brush)
    {
        var cellWidth = Bounds.Width / columns;
        var cellHeight = Bounds.Height / rows;

        const double radius = 5;

        foreach (var player in team.Players)
        {
            if (!player.HasCoordinate)
                continue;

            var coordinate = player.coordinate;

            var center = new Point(
                (coordinate.X + 0.5) * cellWidth,
                (coordinate.Y + 0.5) * cellHeight
            );

            context.DrawEllipse(brush, null, center, radius, radius);
        }
    }
}