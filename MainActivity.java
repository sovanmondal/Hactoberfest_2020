package com.dip.dipay.adapter;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    Spinner spinner;
    String[] res=null;
    List<String> arrayList =new ArrayList<>();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spinner=findViewById(R.id.spinner);
        res=getResources().getStringArray(R.array.country);
        arrayList = Arrays.asList(res);

        ArrayAdapter<String> arrayAdapter =new ArrayAdapter<String>(MainActivity.this,android.R.layout.simple_spinner_item,arrayList){


            @Override
            public boolean isEnabled(int position) {
                if (position == 0){
                    return false;
                }
                else{
                    return true;
                }
            }
        };
        arrayAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(arrayAdapter);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                if (parent.getItemAtPosition(position).equals("Select Country")) {
                }

                else
                    {
                    String item = parent.getItemAtPosition(position).toString();
                    Toast.makeText(parent.getContext(), "you've Selected" + item, Toast.LENGTH_SHORT).show();
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });
    }
}
