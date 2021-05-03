package com.testsqlite;

import android.database.sqlite.SQLiteException;
import com.facebook.react.bridge.JSIModulePackage;
import com.facebook.react.bridge.JSIModuleSpec;
import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;

import java.util.Arrays;
import java.util.List;

public class SQLiteJSIModulePackage implements JSIModulePackage {

    private static native void nativeInit(long jsiPtr, String docPath);


    static {
        System.loadLibrary("joshtest");
    }

    @Override
    public List<JSIModuleSpec> getJSIModules(ReactApplicationContext reactApplicationContext, JavaScriptContextHolder jsContext) {

        try{
            reactApplicationContext.openOrCreateDatabase("helper.db",
                    reactApplicationContext.MODE_PRIVATE, null);
        }catch (SQLiteException exception){
            // Uhh.. we have a situation.
        }

        nativeInit(jsContext.get(), reactApplicationContext.getDatabasePath("helper.db").getParent());
        return Arrays.<JSIModuleSpec>asList();
    }
}