package com.testsqlite;

import com.facebook.react.bridge.JSIModulePackage;
import com.facebook.react.bridge.JSIModuleSpec;
import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;

import java.util.Arrays;
import java.util.List;

public class SQLiteJSIModulePackage implements JSIModulePackage {

    private static native void nativeInit(long jsiPtr);


    static {
        System.loadLibrary("joshtest");
    }

    @Override
    public List<JSIModuleSpec> getJSIModules(ReactApplicationContext reactApplicationContext, JavaScriptContextHolder jsContext) {

        nativeInit(jsContext.get());

        return Arrays.<JSIModuleSpec>asList();
    }

}
