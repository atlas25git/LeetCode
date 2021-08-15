public class SnakeGame {
    private int Width { get; set; }
    private int Height { get; set; }
    private Queue<int[]> Occupied { get; set; }
    private HashSet<string> Snake { get; set; }
    private int[][] Food { get; set; }
    private int Row { get; set; }
    private int Col { get; set; }
    private int FoodCounter { get; set; }
    
    public SnakeGame(int width, int height, int[][] food) {
        Width = width;
        Height = height;
        Occupied = new Queue<int[]>();
        Snake = new HashSet<string>();
        Food = food;
        Row = 0;
        Col = 0;
        FoodCounter = 0;
        
        Occupied.Enqueue(new int[] { 0, 0 });
        Snake.Add("0,0");
    }
    
    public int Move(string direction) {
        switch(direction) {
            case "L":
                Col -= 1;
                break;
            case "R":
                Col += 1;
                break;
            case "U":
                Row -= 1;
                break;
            case "D":
                Row += 1;
                break;
            default:
                throw new Exception($"Unknown direction - {direction}");
        }
        
        return IsValidMove() ? Snake.Count - 1 : -1;
    }
    
    private bool IsValidMove() {
        var cell = $"{Row},{Col}";
        if(Row < 0 || Row >= Height || Col < 0 || Col >= Width) return false;
        
        var food = FoodCounter < Food.Length ? Food[FoodCounter] : new int[] { -1, -1 };
        if(food[0] == Row && food[1] == Col) {
            FoodCounter += 1;
        }
        else {
            var remove = Occupied.Dequeue();
            Snake.Remove($"{remove[0]},{remove[1]}");
        }
        
        if(Snake.Contains(cell)) return false;
        
        Snake.Add(cell);
        Occupied.Enqueue(new int[] { Row, Col });
        
        return true;
    }
}
