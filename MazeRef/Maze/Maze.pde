final int NODE_SIZE = 20;
final int MAZE_SIZE_X = 20;
final int MAZE_SIZE_Y = 20;
final int STEP_MS = 1;

boolean generatorFinished = false;
boolean searchFinished = false;

ArrayList<Node> solution;

Node[][] nodes = new Node[MAZE_SIZE_X][MAZE_SIZE_Y];
//ArrayList<Node> nodes = new ArrayList<Node>();

void settings()
{
  size(NODE_SIZE * MAZE_SIZE_X, NODE_SIZE * MAZE_SIZE_Y);
}

void setup()
{
  background(0);
  frameRate(30);

  for (int i = 0; i < MAZE_SIZE_X; i++)
  {
    for (int j = 0; j < MAZE_SIZE_Y; j++)
    {
      Node node = new Node(i, j);
      if (i == 0 && j == 0)
      {
        node.isStart = true;
      } else if (i == MAZE_SIZE_X - 1 && j == MAZE_SIZE_Y - 1)
      {
        node.isFinish = true;
      }

      nodes[i][j] = node;
    }
  }

  //thread("generate"); // Generate the maze
  
  int deltaTime = millis();
  generate();
  deltaTime = millis() - deltaTime;
  println("Generation time: " + deltaTime + "ms");
}

void draw()
{
  for (int i = 0; i < MAZE_SIZE_X; i++)
  {
    for (int j = 0; j < MAZE_SIZE_Y; j++)
    {
      if (nodes[i][j].changed)
      {
        nodes[i][j].draw();
      }
    }
  }
}

void keyPressed()
{
  if (key == 's' || key == 'S') {
    if (generatorFinished) 
    {
      int deltaTime = millis();
      solution = searchPath(nodes[0][0], nodes[MAZE_SIZE_X - 1][MAZE_SIZE_Y - 1]);
      deltaTime = millis() - deltaTime;
      println("Search time: " + deltaTime + "ms");
      drawPath(solution);
    } else
    {
      println("Wait for the generator to finish!");
    }
  }
}
