package com.aliyun.sls.android.producer.example;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.aliyun.sls.android.producer.example.example.crash.CrashExampleActivity;
import com.aliyun.sls.android.producer.example.example.producer.ProducerExample;
import com.aliyun.sls.android.producer.example.example.producer.ProducerWithDynamicConfig;
import com.aliyun.sls.android.producer.example.example.producer.ProducerWithNoPersistent;
import com.aliyun.sls.android.producer.example.utils.PreferenceUtils;

/**
 * @author gordon
 * @date 2021/08/18
 */
public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
        findViewById(R.id.main_producer_basic).setOnClickListener(this);
        findViewById(R.id.main_producer_persistent).setOnClickListener(this);
        findViewById(R.id.main_producer_dynamic_config).setOnClickListener(this);
        findViewById(R.id.main_apm_crash).setOnClickListener(this);

    }

    @Override
    public void onClick(View v) {
        if (R.id.main_producer_basic == v.getId()) {
            // 基本配置
            startActivity(ProducerExample.class);
        } else if (R.id.main_producer_persistent == v.getId()) {
            // 不带缓存的配置
            startActivity(ProducerWithNoPersistent.class);
        } else if (R.id.main_producer_dynamic_config == v.getId()) {
            // 动态配置
            startActivity(ProducerWithDynamicConfig.class);
        } else if (R.id.main_apm_crash == v.getId()) {
            // 崩溃监控
            startActivity(CrashExampleActivity.class);
        }
    }

    private void startActivity(Class<? extends Activity> clazz) {
        Intent intent = new Intent(this, clazz);
        intent.putExtra("endpoint", PreferenceUtils.getEndpoint(this));
        intent.putExtra("logProject", PreferenceUtils.getLogProject(this));
        intent.putExtra("logStore", PreferenceUtils.getLogStore(this));
        intent.putExtra("accessKeyId", PreferenceUtils.getAccessKeyId(this));
        intent.putExtra("accessKeySecret", PreferenceUtils.getAccessKeySecret(this));
        intent.putExtra("accessKeyToken", PreferenceUtils.getAccessKeyToken(this));

        startActivity(intent);
    }
}
