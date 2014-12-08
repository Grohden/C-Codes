//Please, if u read this, the code below is just for me..i'm a newbie in android and this is just a explaned backup
import java.util.ArrayList;
import java.util.List;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class GenericClass extends ActionBarActivity{
  
  List<String> list=new ArrayList<String>(); //Create a ArrayList of Strings
    		
  ListView listview=(ListView) findViewById(R.id.ListViewId); //get ListView from Layout.xml
  		
  //We need a ArrayAdapter<String> to put the data in the ListView, it recive 3 parameters
  ArrayAdapter<String> adapter=new ArrayAdapter<String>(this, //1 :the app context, or simply "this"
  				android.R.layout.simple_list_item_1,                //2 :a layout for the ListView, that is a Int from R.layout
  				list);                                              //3 :And finally, the list of elements/string/int etc.
  
  	@Override
  	protected void onCreate(Bundle savedInstanceState) {
  		super.onCreate(savedInstanceState);
  		setContentView(R.layout.activity_main); //Set Layout.xml here

  				
  		listanotes.add("Something in postion 0"); //lets add something int pos 0
  		listanotes.add("Something in postion 1"); //and on pos 1
  		
  		 /*finished, we add to ListView an Adapter, that contains 
  		  * the data (3º parameter) and
  		 */ the type of the list(second paramether)
  		listview.setAdapter(adapter);
  		/*if u want to add something in the ArrayList after set the adapter,
  		*/ u will need to add the data, and use notifyDataSetChanged()
  		
  		
  		//here we add a on click item method
  		listview.setOnItemClickListener(new OnItemClickListener() {
  			@Override
  			public void onItemClick(AdapterView<?> arg0, View arg1, int position,
  					long arg3) { 
  					switch (position){
  					case 0:
  						startActivity(new Intent(getApplicationContext(),OtherActivityClass.class));
  						break;
  					case 1:
  						Toast.makeText(getApplicationContext(), "position = "+position, Toast.LENGTH_LONG).show();
  						break;
  				                	}
  			        
  			              }
  			});
  
  	}
