package justjava;
public class Connector {
    int list[];
    
    public Connector(int len){
        list = new int[len];

        for(int runner = 0; runner < len;runner++){
            list[runner] = runner;
        }
    }


    public void union(int first,int second){
        int firstItem = list[first];
        int secondItem = list[second];

        for(int runner = 0; runner < list.length; runner++){
            if(list[runner] == firstItem){
                list[runner] = secondItem;
            }
        }
    }

    public boolean isConnected(int first, int second){
        if(list[first] == list[second]){
            return true;
        }else{
            return false;
        }
    }

    public void printOut(){
        for(int runner = 0; runner < list.length; runner++){
          System.out.println("Index: " + runner + " Value: " + list[runner]);
        }
    }


    public static void main(String[] args){
        Connector example = new Connector(10);

        example.printOut();
    }
}