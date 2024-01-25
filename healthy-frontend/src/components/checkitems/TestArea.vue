<template>
    <div>
        
        <el-form :inline="true"  class="demo-form-inline">
            <el-form-item label="体检提醒或影像所见" class="bold-label">
                    <el-input type="textarea"  
                    :rows="6"
                    :autosize="{ minRows: 6, maxRows: 10 }"
                    width="50%" 
                    class="suibian"
                    v-model="textarea1"
                    placeholder="输入以多个,分隔">

                    </el-input>
            </el-form-item>
            <el-form-item label="体检小结" class="bold-label">
                    <el-input type="textarea"  
                    :rows="6"
                    :autosize="{ minRows: 6, maxRows: 10 }"
                    width="50%" 
                    class="suibian"
                    v-model="textarea2"
                    placeholder="输入以多个,分隔">
                    </el-input>
            </el-form-item>
            <el-form-item label="检查医生" class="bold-label">
                <el-select
                     v-model="wbk.ssks"
                     class="m-2"
                     placeholder="请选择"
                     size="large"
                     style="width: 240px"
  >

            <el-option
                v-for="item in props.tcObject.selectDown "
                :key="item"
                :label="item.label"
                :value="item.label"
    />
  </el-select>
</el-form-item>
<el-form-item label="检查日期" class="bold-label">
                    <el-input type="date"  
                    width="50%" 
                    class="suibian"
                    v-model="date"
                    >
                    </el-input>
            </el-form-item>
        </el-form>
    </div>
  </template>
  
  <script setup>

import { reactive,ref,defineProps,watch,defineEmits} from 'vue'

const textarea1 = ref()
const textarea2 = ref()

// 定义抽屉预设
const props = defineProps({
  //包含数据 列 是否显示确定取消按钮
    tcObject:{
      type: Object,
      default: () =>({bottonTitle:'按钮名字',tableTitle:'抽屉表头',
      //是否显示确定取消按钮
      isShowButtonForTc:true,
      //控制触发按钮是否隐藏
      hideButton:false,
      //控制抽屉是否打开
      openDrawer:false,
      //表格列属性
      tableLieForTc:[{
        prop:'bind',
        label:'列的显示名称'
      },
      {
        prop:'bind2',
        label:'列的显示名称'
      }],
      //表格字段
      tableDataForTc:[{
        bind:'列的显示字段名',
        bind2:'列的显示字段名'
      }],
      //下拉框
      selectDown:[{
        value:'字段属性值-绑定用',
        label:'下拉显示的数据'
      }],
      required:true
    })
    }
})

  // 搜索框的字段存放区域-套餐项目
  const wbk = reactive({
  tjtx: '',
  ssks: ''
})

</script>
  
  <style lang="scss">
  .suibian{
  display: flex;
      justify-content: space-between;
      align-items: center;
}
</style>
  